class UnionFind:
    def __init__(self, N):
        # parent[i] = i initially, each river is its own parent
        self.parent = list(range(N))
        # size[i] = volume of water in river i
        self.size = [0] * N
        # name[i] = name of the river (index of the source)
        self.name = list(range(N))
    
    # Find operation with path compression
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    # Union by size, merge rivers a and b
    def union(self, a, b):
        rootA = self.find(a)
        rootB = self.find(b)
        
        if rootA != rootB:
            if self.size[rootA] > self.size[rootB]:
                self.parent[rootB] = rootA
            elif self.size[rootA] < self.size[rootB]:
                self.parent[rootA] = rootB
            else:
                # If the sizes are equal, choose by name (lower index)
                if self.name[rootA] < self.name[rootB]:
                    self.parent[rootB] = rootA
                else:
                    self.parent[rootA] = rootB
            
            # Update the size of the new root
            newRoot = self.find(rootA)  # Find new root after union
            self.size[newRoot] = self.size[rootA] + self.size[rootB]
            # Update the name of the new root
            self.name[newRoot] = min(self.name[rootA], self.name[rootB])
    
    # Add water to a river
    def add_water(self, river, water):
        root = self.find(river)
        self.size[root] += water

    # Get the name of the river that flows into the sea
    def get_main_river(self):
        return self.name[self.find(0)]

# Input Reading
N = int(input())
li = list(map(int, input().split()))

# Initialize Union-Find structure
uf = UnionFind(2 * N - 1)

# Set initial sizes (volumes of water) for rivers
for i in range(N):
    uf.size[i] = li[i]

# Process river joins
for i in range(N - 1):
    a, b = map(int, input().split())
    uf.union(a - 1, b - 1)

# Output the initial name of the river flowing into the sea
print(uf.get_main_river() + 1)

# Process queries
Q = int(input())
for _ in range(Q):
    n, q = map(int, input().split())
    uf.add_water(n - 1, q)
    print(uf.get_main_river() + 1)
