#include <vector>
using namespace std;

class Access 
{
    public:
        void activate(unsigned int code);
        void deactivate(unsigned int code);
        bool isactive(unsigned int code) const;
    private:
        vector<int> codes;
};