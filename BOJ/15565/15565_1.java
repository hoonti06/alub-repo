/*
* 메모리: 73664 KB, 시간: 440 ms
* 타이머 시간: null
* 2021.11.10
* by Alub
**/
import java.io.*;
import java.util.*;

public class Main {
    static int N, K;
    static int[] input;
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        input = new int[N];
        st = new StringTokenizer(in.readLine(), " ");
        for (int i = 0; i < N; i++) {
            input[i] = Integer.parseInt(st.nextToken());
        }

        int ryanCnt = 0;
        int cur = 0;
        int prev = 0;
        while (ryanCnt < K && cur < N) {
            if (input[cur] == 1) {
                if (++ryanCnt == 1) {
                    prev = cur;
                }
            }
            cur++;
        }
        cur--;
        int res = -1;
        if (ryanCnt < K) {
            System.out.println(-1);
        } else {
            res = cur - prev;
            while (cur < N) {
                cur++;
                while (cur < N && input[cur] == 2) {
                    cur++;
                }
                if (cur >= N) {
                    break;
                }
                prev++;
                while (prev <= cur && input[prev] == 2) {
                    prev++;
                }
                res = Math.min(res, cur - prev);
            }
            System.out.println(res + 1);
        }
    }
}
