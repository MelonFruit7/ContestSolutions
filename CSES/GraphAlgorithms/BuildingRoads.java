import java.util.*;
import java.io.*;

class DSU {
    int[] par, sz;
    public DSU(int n) {
        par = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u) {
        if (u != par[u]) return par[u] = find(par[u]);
        return u;
    }
    boolean join(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        par[b] = par[a];
        sz[a] += sz[b];
        return true;
    }
}
public class BuildingRoads {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());

        TreeSet<Integer> t = new TreeSet<>();
        DSU d = new DSU(n);
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken())-1, b = Integer.parseInt(st.nextToken())-1;
            d.join(a, b);
        }
        for (int i = 0; i < n; i++) t.add(d.find(i));

        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        pw.println(t.size()-1);
        int prev = -1;
        for (int num : t) {
            if (prev == -1) {
                prev = num;
            } else {
                pw.println((prev+1)+" "+(num+1));
                prev = num;
            }
        }
        br.close();
        pw.close();
    }
}