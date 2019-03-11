#include<vector>
#include<math>
#include<random>
using namespace std;
/*
注意：它需要产生在圆内均匀分布的点。极坐标下，角度可以直接取均匀分布uniform，
    但半径不可以直接取均匀分布，这样会导致离圆心近的点更密集。需要对均匀分布开方，具体证明参考:
    https://stackoverflow.com/questions/5837572/generate-a-random-point-within-a-circle-uniformly/50746409#50746409
*/
class Solution {
public:
    Solution(double radius, double x_center, double y_center) :
        m_radius(radius),
        m_x_center(x_center),
        m_y_center(y_center),
        m_rng((random_device())()),
        m_uni(0.0, 1.0) {
        
    }
    
    vector<double> randPoint() {
        const auto r = m_radius * sqrt(m_uni(m_rng));
        const auto theta = (2 * M_PI) * m_uni(m_rng);
        return {r * cos(theta) + m_x_center,
                r * sin(theta) + m_y_center};
    }
private:
    double m_radius;
    double m_x_center;
    double m_y_center;
    default_random_engine m_rng;
    uniform_real_distribution<double> m_uni;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */