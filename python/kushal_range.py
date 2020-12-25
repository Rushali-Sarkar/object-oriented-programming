class Range:

    def __init__(self, *args):
        if len(args) == 0:
            self.start = 0
            self.end = 0
        elif len(args) == 1:
            self.start = 0
            self.end = args[0]
        elif len(args) == 2:
            self.start = args[0]
            self.end = args[1]
        else:
            raise ValueError
        return

    def __repr__(self):
        return f"[{self.start}, {self.end}]"

    def __len__(self):
        return self.end - self.start + 1

    def __eq__(self, rng):
        return self.start == rng.start and self.end == rng.end

    def reset(self):
        pass

    def rstretch(self):
        pass

    def lstretch(self):
        pass

    def stretch(self):
        pass

    def rsqueeze(self):
        pass

    def lsqueeze(self):
        pass

    def squeeze(self):
        pass

    def shift(self):
        pass

    def contains(self):
        pass

    def is_subset(self):
        pass


if __name__ == "__main__":
    r = Range(9)
    print(r)
    print(len(r))
    a = Range(0, 8)
    print(r == a)