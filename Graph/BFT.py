G = {
    'A': ['M', 'Q'],
    'M': ['A','Z','C'],
    'Q': ['A','Y','R'],
    'Z': ['M'],
    'C': ['M'],
    'Y': ['Q'],
    'R': ['Q']
}
def BFT(G, start):
    queue = []
    visited = []
    queue.append(start)
    while(queue):        # Repeat until the queue is not empty
        poppedVertex = queue.pop(0)  #     queue behaviour means FIFO 
        visited.append(poppedVertex)
        for chimeki in G[poppedVertex]:
            if chimeki not in visited and chimeki not in queue:
                queue.append(chimeki)
    return visited

start = 'A'
print(BFT(G, start))