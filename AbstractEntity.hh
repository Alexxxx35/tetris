#ifndef DEF_ABSTRACTENTITY
#define DEF_ABSTRACTENTITY
#include <string>
class AbstractEntity
{
public:
    virtual ~AbstractEntity();
    virtual void Draw() = 0;
    virtual void Update() = 0;
    virtual std::string Serialize() = 0;

protected:
    AbstractEntity();
};

#endif
