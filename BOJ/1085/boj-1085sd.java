/**
* 메모리: 17572 KB, 시간: 208 ms
* 2021.11.18
* by Alub
*/
import java.io.FileInputStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int res = Integer.MAX_VALUE;
        int x = sc.nextInt();
        int y = sc.nextInt();
        int w = sc.nextInt();
        int h = sc.nextInt();

        int minWidth = Math.min(x, w-x);
        int minHeight = Math.min(y, h-y);
        res = Math.min(minWidth, minHeight);
        System.out.println(res);
    }
}