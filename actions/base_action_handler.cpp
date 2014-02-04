#include "base_action_handler.h"

BaseActionHandler::BaseActionHandler(T* object) : mObject(object) {}

std::vector<ActionPhrase BaseActionHandler::getActions() const {
    std::vector<ActionPhrase> actionPhrases;

    for (int i = 0; i < mActions.size(); ++i) {
        if (mActions[i]->test()) {
            actionPhrases.push_back(mActions[i]->actionPhrase());
        }
    }

    return actionPhrases;
}

bool BaseActionHandler::runAction(const ActionPhrase action) const {
    for (int i = 0; i < mActions.size(); ++i) {
        if (strcmp(action, mActions[i]->actionPhrase()) == 0) {
            if (mActions[i]->test(mObject)) {
                mActions[i]->callback(mObject);
                return true;
            }
        }
    }

    return false;
}

void BaseActionHandler::registerAction(ActionPhrase phrase, ActionTest test, ActionCallback callback) {
    mActions.push_back({phrase, test, callback});
}
