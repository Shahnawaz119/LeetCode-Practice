class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flights(n);
        for(int i=0; i<bookings.size(); i++){
            int l=bookings[i][0];
            int r=bookings[i][1];
            int v=bookings[i][2];
            flights[l-1]+=v;
            if(r<n){
                flights[r]-=v;
            }
        }
        for(int i=1; i<n; i++){
            flights[i]+=flights[i-1];
        }
        return flights;
    }
};