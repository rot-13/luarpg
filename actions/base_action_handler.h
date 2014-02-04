#ifndef BASE_ACTION_HANDLER_H_
#define BASE_ACTION_HANDLER_H_

#include <vector>

typedef const char* ActionPhrase;

template<class T>
class BaseActionHandler {
    public:
        BaseActionHandler(T& object);
        std::vector<ActionPhrase> getActions() const;
        bool runAction(const ActionPhrase) const;

    protected:
        typedef bool (*ActionTest)(const T&);
        typedef void (*ActionCallback)(const T&);

        typedef struct {
            ActionPhrase actionPhrase;
            ActionTest test;
            ActionCallback callback;
        } Action;

        void registerAction(ActionPhrase, ActionTest, ActionCallback);
        std::vector<Action*> mActions;
        T& mObject;
};

#endif BASE_ACTION_HANDLER_H_
