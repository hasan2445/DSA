class Solution {
public:
    vector<double> internalAngles(vector<int>& side) {
        const double pi=3.14159265359;
        double PI = acos(-1.0);
        if(side[0]+side[1]<=side[2]||side[2]+side[1]<=side[0]||side[0]+side[2]<=side[1]) return {};
        //double  x=side[0]/2.0;
        //double pi = acos(-1.0);
        double d=(double)(2.0);
        double a=acos((side[0]*side[0]+side[1]*side[1]-side[2]*side[2])/(d*side[0]*side[1]));
        double b=acos((side[0]*side[0]+side[2]*side[2]-side[1]*side[1])/(d*side[0]*side[2]));
        double  c=acos((side[2]*side[2]+side[1]*side[1]-side[0]*side[0])/(d*side[2]*side[1]));
        vector<double>v;
        //if(a*180/pi>=180 || b*180/pi>=180 ||c*180/pi >=180) return {};
        v.push_back(a*180/pi);
        v.push_back(b*180/pi);
        v.push_back(c*180/pi);
        sort(v.begin(),v.end());
        return v;
    }
};