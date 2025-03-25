#define pii pair<int,int>
public:
    bool checkslice(vector<pii>& coordinates){
        int lines = 0;
        int overlap = 0;
        for(int i = 0;i < coordinates.size();i++){
            if(coordinates[i].second == 0){
                overlap--;
            }
            else{
                overlap++;
            }
            if(overlap==0)lines++;

        }
        if(lines>=3)return true;
        else{
            return false;
        }
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pii>y_coordinates,x_coordinates;
        for(auto& rectangle: rectangles){
            y_coordinates.push_back(make_pair(rectangle[1],1));
            y_coordinates.push_back(make_pair(rectangle[3],0));
            x_coordinates.push_back(make_pair(rectangle[0],1));
            x_coordinates.push_back(make_pair(rectangle[2],0));
        }
        sort(y_coordinates.begin(),y_coordinates.end());
        sort(x_coordinates.begin(),x_coordinates.end());
        return (checkslice(y_coordinates) or checkslice(x_coordinates));
    }
