public class Odometer {
    static String digits = "123456789";

    private int SIZE;
    private int START;
    private int LIMIT;
    private int reading;

    public static void main(String[] args) {
        Odometer o = new Odometer(Integer.parseInt(args[0]));
        o.debug();
	o.next();
        o.debug();
	o.next(10);
	o.debug();
	o.prev(7);
	o.debug();
	o.prev(6);
	o.debug();
	Odometer p = new Odometer(o);
	o.next(12);
	System.out.println(p.distance(o));

    }

    private void debug() {
       System.out.println(this.START + " << " + this.reading + " >> " + this.LIMIT);
    }

    
    public Odometer(int size) {
        this.SIZE = size;
        this.START = Integer.parseInt(Odometer.digits.substring(0, size));
        this.LIMIT = Integer.parseInt(digits.substring(9 - size));
        this.reading = this.START;
    }

    public Odometer(Odometer o) {
        this.START = o.START;
        this.LIMIT = o.LIMIT;
        this.reading = o.reading;
    }

    private static boolean isAscending(int n) {
        if (n < 10) return true;
        if (n % 10 <= (n / 10) % 10) {
            return false;
        }
        return isAscending(n / 10);
    }

    public void next() {
        if (this.reading == this.LIMIT) {
            this.reading = this.START;
            return;
        }
        do {
            ++this.reading;
        } while (!isAscending(this.reading));
        return;
    }

    public void next(int n) {
        for (int i = 0; i < n; ++i) {
            this.next();
        }
        return;
    }

    public void prev() {
        if (this.reading == this.START) {
            this.reading = this.LIMIT;
            return;
        }
        do {
            --this.reading;
        } while (!isAscending(this.reading));
        return;
    }

    public void prev(int n) {
        for (int i = 0; i < n; ++i) {
            this.prev();
        }
        return;
    }

    public int distance(Odometer o) {
        int diff = 0;
	Odometer copy = new Odometer(this);
	while (o.reading != copy.reading) {
	    copy.next();
	    ++diff;
        }
	return diff;
    }
}
