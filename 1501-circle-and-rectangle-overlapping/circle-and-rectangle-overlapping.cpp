class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int np = xCenter;
        int mp = yCenter;
        int r = radius;

        
        if (np >= x1 && np <= x2 && mp >= y1 && mp <= y2)
            return true;

        
        if (np < x1 && mp >= y1 && mp <= y2) {
            if (x1 - np <= r)
                return true;
        }

        if (np > x2 && mp >= y1 && mp <= y2) {
            if (np - x2 <= r)
                return true;
        }

        
        if (mp < y1 && np >= x1 && np <= x2) {
            if (y1 - mp <= r)
                return true;
        }

        if (mp > y2 && np >= x1 && np <= x2) {
            if (mp - y2 <= r)
                return true;
        }

        
        if (np < x1 && mp < y1) {
            int dx = x1 - np;
            int dy = y1 - mp;
            if (dx * dx + dy * dy <= r * r)
                return true;
        }

        if (np < x1 && mp > y2) {
            int dx = x1 - np;
            int dy = mp - y2;
            if (dx * dx + dy * dy <= r * r)
                return true;
        }

        if (np > x2 && mp < y1) {
            int dx = np - x2;
            int dy = y1 - mp;
            if (dx * dx + dy * dy <= r * r)
                return true;
        }

        if (np > x2 && mp > y2) {
            int dx = np - x2;
            int dy = mp - y2;
            if (dx * dx + dy * dy <= r * r)
                return true;
        }

        return false;
    }
};