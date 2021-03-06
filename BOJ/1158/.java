/*
* 메모리: 292476 KB, 시간: 516 ms
* 타이머 시간: null
* 2021.11.16
* by Alub
**/
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N, K;
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 1; i <= N; i++)
            q.offer(i);

        StringBuilder sb = new StringBuilder();
        sb.append("<");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K-1; j++)
                q.offer(q.poll());
            sb.append(q.poll()).append(", ");
        }

        sb.setLength(sb.length()-2);
        sb.append(">");
        System.out.println(sb);
    }
}

