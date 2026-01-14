class Solution {

    static class Event {
        double y;
        int x1, x2;
        int type; //1: add,-1: remove

        Event(double y, int x1, int x2, int type) {
            this.y = y;
            this.x1 = x1;
            this.x2 = x2;
            this.type = type;
        }
    }

    static class SegTree {
        int n;
        int[] count;
        double[] len;
        double[] xs;

        SegTree(double[] xs) {
            this.xs = xs;
            this.n = xs.length - 1;
            count = new int[n * 4];
            len = new double[n * 4];
        }

        void update(int node, int l, int r, int ql, int qr, int val) {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) {
                count[node] += val;
            } else {
                int mid = (l + r) / 2;
                update(node * 2, l, mid, ql, qr, val);
                update(node * 2 + 1, mid, r, ql, qr, val);
            }

            if (count[node] > 0) {
                len[node] = xs[r] - xs[l];
            } else if (l + 1 == r) {
                len[node] = 0;
            } else {
                len[node] = len[node * 2] + len[node * 2 + 1];
            }
        }

        double query() {
            return len[1];
        }
    }

    public double separateSquares(int[][] squares) {

                List<Event> events = new ArrayList<>();
        TreeSet<Double> xSet = new TreeSet<>();

        for (int[] s : squares) {
            double x = s[0], y = s[1], l = s[2];
            xSet.add(x);
            xSet.add(x + l);
        }

        double[] xs = new double[xSet.size()];
        int idx = 0;
        for (double v : xSet) xs[idx++] = v;

        Map<Double, Integer> xIndex = new HashMap<>();
        for (int i = 0; i < xs.length; i++) xIndex.put(xs[i], i);

        for (int[] s : squares) {
            double x = s[0], y = s[1], l = s[2];
            int lIdx = xIndex.get(x);
            int rIdx = xIndex.get(x + l);
            events.add(new Event(y, lIdx, rIdx, +1));
            events.add(new Event(y + l, lIdx, rIdx, -1));
        }

        events.sort(Comparator.comparingDouble(e -> e.y));

        SegTree st = new SegTree(xs);

        List<double[]> strips = new ArrayList<>();
        double prevY = events.get(0).y;
        double totalArea = 0;

        int i = 0;
        while (i < events.size()) {
            double currY = events.get(i).y;
            double dy = currY - prevY;
            double width = st.query();

            if (dy > 0 && width > 0) {
                strips.add(new double[]{prevY, currY, width});
                totalArea += width * dy;
            }

            while (i < events.size() && events.get(i).y == currY) {
                Event e = events.get(i);
                st.update(1, 0, st.n, e.x1, e.x2, e.type);
                i++;
            }
            prevY = currY;
        }

        double target = totalArea / 2;
        double acc = 0;

        for (double[] s : strips) {
            double y1 = s[0], y2 = s[1], w = s[2];
            double area = w * (y2 - y1);
            if (acc + area >= target) {
                return y1 + (target - acc) / w;
            }
            acc += area;
        }

        return prevY;
        
    }
}