class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(self.size)]
        
    def __repr__(self):
        return str(self.table)
        
    def hash_func(self, key):
        return hash(key) % self.size # insert custom hash method here 

            
    def insert(self, key, value):
        hash_idx = self.hash_func(key)
        bucket = self.table[hash_idx]
        
        for item in bucket:
            if item[0] == key:
                item[1] = value
                return
        bucket.append([key, value])
            
        
    def find(self, key):
        hash_idx = self.hash_func(key)
        bucket = self.table[hash_idx]
        
        for item in bucket:
            if item[0] == key:
                return item[1]
        

# square = HashTable(size=2)
# square.insert("color", "blue")
# square.insert("side", "4")
# square.insert("name", "Timmy")
# print(square.find("name"))
