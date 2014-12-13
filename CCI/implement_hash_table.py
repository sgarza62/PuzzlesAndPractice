class Table():
    def __init__(self, size=1000):
        self.size = size
        self.buckets = [[]] * size # [[], [], [], ... , []]

    def table_hash(self, key):
        '''
        A hash function is any function that can be used to map data of
        arbitrary size to data of fixed size, with slight differences in input
        data producing very big differences in output data.
        '''
        assert(type(key) == str)

        h = 0
        for i in range(len(key)):
            h += ord(key[i]) * 13001
        return h % self.size
    
    def insert(self, key, value):
        index = self.table_hash(key)
        self.buckets[index].append((key, value))

    def access(self, key):
        index = self.table_hash(key)
        b = self.buckets[index]
        for tup in b:
            if tup[0] == key:
                return tup[1]
        else:
            raise Exception("No hash table element exists for the key %s" % key)
    
    def delete(self, key):
        index = self.table_hash(key)
        b = self.buckets[index]
        for i, tup in enumerate(b):
            if tup[0] == key:
                self.buckets[index].pop(i)
        else:
            raise Exception("No hash table element exists for the key %s" % key)
