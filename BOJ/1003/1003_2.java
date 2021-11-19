/**
* 메모리: 16004 KB, 시간: 148 ms
* 풀이 시간: 00:00:30
* 2021.11.19
* by Alub
*/
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static int T, N;
    static int[] num = new int[41];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine().trim());
        num[1] = 1;

        while (T-- > 0) {
            N = Integer.parseInt(br.readLine().trim());
            if (N == 0)
                sb.append(1 + " " + 0 + "\n");
            else {
                if (num[N] == 0)
                    fibonacci(N);
                sb.append(num[N - 1] + " " + num[N] + "\n");
            }
        }

        System.out.println(sb);
    }

    private static int fibonacci(int n) {
        if (n == 0 || num[n] != 0) {
            return num[n];
        }

        return num[n] = fibonacci(n - 2) + fibonacci(n - 1);
    }
}