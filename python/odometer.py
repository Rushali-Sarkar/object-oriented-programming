"""If you try to call an object without calling its constructor then the constructor will catch up, I do not know who the hell the
object is """


def __is_ascending__(n):
    if n < 10: 
        return True
    if n % 10 <= (n // 10) % 10:
        return False
    return __is_ascending__(n // 10)

class Odometer():

    def __init__(self, size: int):
        self.LIMIT = 10 ** size
        self.START = self.LIMIT // 10
        self.reading = self.START

    def next_reading(self, step = 1):
        for _ in range(step):

            if self.reading == self.LIMIT:
                self.reading = self.START
            else:
                self.reading += 1
                while not  ___is_ascending__(self.reading):
                    self.reading += 1
    
    def prev_reading(self, step = 1):
        for _ in range(step):

            if self.reading == self.START:
                self.reading = self.LIMIT

            else: 
                self.reading -= 1
                while not __is_ascending__(self.reading):
                    self.reading -= 1

    def __repr__(self):
        return str(self.START) + " << " + str(self.reading) + " >> " + str(self.LIMIT)

    def DEBUG(self):
        print("START: ", self.START)
        print("LIMIT: ", self.LIMIT)
        print("CURRENT: ", self.reading)



































o = Odometer(3)
print(o)



