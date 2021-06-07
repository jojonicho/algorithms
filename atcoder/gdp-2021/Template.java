import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

import javax.swing.text.JTextComponent.KeyBinding;

// command constants
enum Command {
    ONE, TWO, THREE, FOUR
}

public class Template {

    private static PrintWriter out = new PrintWriter(System.out);

    private static void executeCommand(String[] raw) {
        String command = raw[0];
        // execute command here
        if (command.equals(Command.ONE.name())) {

        } else if (command.equals(Command.TWO.name())) {

        } else if (command.equals(Command.THREE.name())) {

        } else if (command.equals(Command.FOUR.name())) {

        }
    }

    public static void main(String[] args) {
        try {
            out = new PrintWriter(System.out);
        } catch (Exception e) {
            System.out.println(e);
        }
        FastScanner in = new FastScanner();
        int n = in.nextInt();
        int[][] intervals = new int[n][2];

        for (int i = 0; i < n; i++) {
            int start, end;
            start = in.nextInt();
            end = in.nextInt();
            int curInterval[] = new int[2];
            curInterval[0] = start;
            curInterval[1] = end;
            intervals[i] = curInterval;
        }
        int[][] ans = merge(intervals);
        for (int[] a : ans) {
            out.println(a[0] + " " + a[1]);
        }
        out.flush();
    }

    private static int[][] merge(int[][] intervals) {
        if (intervals.length < 2)
            return intervals;
        List<int[]> ans = new ArrayList<>();
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int[] cur = intervals[0];
        ans.add(cur);
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= cur[1]) {
                cur[1] = Math.max(intervals[i][1], cur[1]);
            } else {
                cur = intervals[i];
                ans.add(intervals[i]);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            return st.nextToken();
        }

        String readLine() {
            try {
                String line = br.readLine();
                return line;
            } catch (IOException e) {
            }
            return null;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}