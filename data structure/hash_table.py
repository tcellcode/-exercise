class HashTableError(Exception):
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)


class HashTable:
    def __init__(self, size=10) -> None:
        self.size = size
        self.table = [[] for _ in range(self.size)]
        
    def __repr__(self) -> str:
        return str(self.table)
        
    def hash_func(self, key):
        return hash(key) % self.size
      
    def insert(self, key, value):
        hash_idx = self.hash_func(key)
        bucket = self.table[hash_idx]
        
        for item in bucket:
            if item[0] == key:
                item[1] = value
                return
            
        bucket.append([key, value])
            
        
    def search(self, key):
        hash_idx = self.hash_func(key)
        bucket = self.table[hash_idx]
        
        for item in bucket:
            if item[0] == key:
                return item[1]
    
    def delete(self, key):
        hash_idx = self.hash_func(key)
        bucket = self.table[hash_idx]
        key_exist = False
        
        for idx, item in enumerate(bucket):
            if item[0] == key:
                key_exist = True
        
        if key_exist:
            del bucket[idx]
        else:
            raise HashTableError(f"Key {key} not existed!")
    

