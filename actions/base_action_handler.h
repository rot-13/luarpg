#ifndef BASE_ACTION_HANDLER_H_
#define BASE_ACTION_HANDLER_H_

#include <vector>
#include <functional>

typedef const char* ActionPhrase;

template<class T>
class BaseActionHandler {
    public:
        BaseActionHandler(T& object) : mObject(object) {}

        std::vector<ActionPhrase> getActions() const {
            std::vector<ActionPhrase> actionPhrases;

            for (int i = 0; i < mActions.size(); ++i) {
                if (mActions[i].test(mObject)) {
                    actionPhrases.push_back(mActions[i].actionPhrase);
                }
            }

            return actionPhrases;
        }

        bool runAction(const ActionPhrase action) const {
            for (int i = 0; i < mActions.size(); ++i) {
                if (strcmp(action, mActions[i].actionPhrase) == 0) {
                    if (mActions[i].test(mObject)) {
                        mActions[i].callback(mObject);
                        return true;
                    }
                }
            }

            return false;
        }

    protected:
        typedef std::function<bool(const T&)> ActionTest;
        typedef std::function<void(T&)> ActionCallback;

        typedef struct {
            ActionPhrase actionPhrase;
            ActionTest test;
            ActionCallback callback;
        } Action;

        void registerAction(ActionPhrase phrase, ActionTest test, ActionCallback callback) {
            mActions.push_back({phrase, test, callback});
        }

        std::vector<Action> mActions;
        T& mObject;
};

#endif // BASE_ACTION_HANDLER_H_
