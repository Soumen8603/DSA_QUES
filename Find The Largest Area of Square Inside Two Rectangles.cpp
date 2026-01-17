long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        long long maxSquareArea = 0;
        for (int i = 0; i < bottomLeft.size(); ++i) {
            int rect1_x1 = bottomLeft[i][0];
            int rect1_y1 = bottomLeft[i][1];
            int rect1_x2 = topRight[i][0];
            int rect1_y2 = topRight[i][1];

            for (int j = i + 1; j < bottomLeft.size(); ++j) {
                int rect2_x1 = bottomLeft[j][0];
                int rect2_y1 = bottomLeft[j][1];
                int rect2_x2 = topRight[j][0];
                int rect2_y2 = topRight[j][1];

                int overlapWidth =
                    min(rect1_x2, rect2_x2) - max(rect1_x1, rect2_x1);
                int overlapHeight =
                    min(rect1_y2, rect2_y2) - max(rect1_y1, rect2_y1);

                int maxSquareSide = min(overlapWidth, overlapHeight);

                if (maxSquareSide > 0) {
                    maxSquareArea = max(maxSquareArea,
                                        static_cast<long long>(maxSquareSide) *
                                            maxSquareSide);
                }
            }
        }
        return maxSquareArea;
    }
