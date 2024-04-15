import java.io.*;
import java.util.*;

public class H_Improving_Chewing_Candy {
    static final long MOD = 1000000007;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static StringTokenizer st;

    static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int k = nextInt();
        String s = next();
        String t;
        int i = 0;
        while (i < n && s.charAt(i) == s.charAt(0))
            i++;
        t = s.substring(i) + s.substring(0, i);
        if (i == n) {
            out.println("-1");
            out.close();
            return;
        }

        ArrayList<Pair> pro = new ArrayList<>();
        int qt = 1, last = 0;
        s = t + t;
        for (int j = 1; j < s.length(); j++) {
            if (s.charAt(j) == s.charAt(last)) {
                qt++;
            } else {
                pro.add(new Pair(qt, last));
                qt = 1;
                last = j;
            }
        }
        pro.add(new Pair(qt, last));

        int[] cont = new int[30];
        i = 0;
        int j = 1, big = s.charAt(pro.get(0).second) - 'a';
        cont[big] = pro.get(0).first;
        TreeSet<Pair> st = new TreeSet<>((a, b) -> a.first == b.first ? a.second - b.second : a.first - b.first);
        st.add(new Pair(-cont[big], big));
        int sz = pro.get(0).first;
        int best = -1, inib = -1;

        while (i < pro.size()) {
            if (-st.first().first <= k) {
                if (sz > best && sz <= n) {
                    best = sz;
                    inib = pro.get(i).second;
                }
            }
            if (-st.first().first > k || j == pro.size()) {
                int id = s.charAt(pro.get(i).second) - 'a';
                st.remove(new Pair(-cont[id], id));
                cont[id] -= pro.get(i).first;
                st.add(new Pair(-cont[id], id));
                sz -= pro.get(i).first;
                i++;
            } else {
                int id = s.charAt(pro.get(j).second) - 'a';
                st.remove(new Pair(-cont[id], id));
                cont[id] += pro.get(j).first;
                st.add(new Pair(-cont[id], id));
                sz += pro.get(j).first;
                j++;
            }
        }

        out.println(best);
        if (best != -1)
            out.println(s.substring(inib, inib + best));
        out.close();
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}
