#include <vector>

class BaseActionHandler {
    public:
        virtual std::vector<const char*> getActions() = 0;
        virtual void runAction(const char* action) = 0;
};
