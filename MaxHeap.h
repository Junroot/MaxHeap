//
//  MaxHeap.h
//  MaxHeap
//
//  Created by Junroot on 2016. 8. 27..
//  Copyright © 2016년 ROOT. All rights reserved.
//

#ifndef MaxHeap_h
#define MaxHeap_h

typedef struct heapElem
{
    int pr; //우선순위
    char data;
}HeapElem;

typedef struct heap
{
    int nod; //데이터 개수
    HeapElem heapArr[100];
}Heap;

void HeapInit(Heap *ph)
{
    ph->nod = 0;
    
}

int GetHiPriChildIDX(Heap *ph, int idx)
{
    if (ph->nod < idx * 2) return 0;
    else if (ph->nod == idx * 2) return idx * 2;
    else
    {
        if (ph->heapArr[idx*2].pr > ph->heapArr[idx*2+1].pr)
        {
            return idx*2;
        }
        else
        {
            return idx*2+1;
        }
    }
}

void HInsert(Heap *ph, char data, int pr)
{
    int idx = ph->nod+1;
    HeapElem newHE = {pr,data};
    while (idx != 1)
    {
        if (pr > ph->heapArr[idx/2].pr)
        {
            ph->heapArr[idx] = ph->heapArr[idx/2];
            idx /= 2;
        }
        else
        {
            break;
        }
    }
    ph->heapArr[idx] = newHE;
    ph->nod += 1;
}

int HDelete(Heap * ph)
{
    int res = ph->heapArr[1].pr;
    HeapElem lastHE = ph->heapArr[ph->nod];
    int parentIdx = 1;
    int childIdx;
    
    if (ph->nod < 1)    exit(-1);
    
    while (childIdx = GetHiPriChildIDX(ph,parentIdx))
    {
        if (lastHE.pr < ph->heapArr[childIdx].pr)
        {
            ph->heapArr[parentIdx] = ph->heapArr[childIdx];
            parentIdx = childIdx;
        }
        else
        {
            break;
        }
    }
    ph->heapArr[parentIdx] = lastHE;
    ph->nod -= 1;
    return res;
}

#endif /* MaxHeap_h */
