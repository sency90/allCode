public class MySingleton{
    static MySingleton single = null;

    public static MySingleton getInstance() {
        if(single == null) single = new MySingleton();
        return single;
    }

    protected MySingleton() {
        System.out.println("--MySingleton()--");
    }

    public static void main(String[] args) {
        MySingleton m = MySingleton.getInstance();
    }
}
