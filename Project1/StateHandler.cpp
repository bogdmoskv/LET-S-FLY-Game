#include "StateHandler.h"


	void StateHandler::addState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateHandler::removeState()
	{
		this->_isRemoving = true;
	}

	void StateHandler::processStateChanges()
	{
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();
			if (!this->_states.empty())
			{
				this->_states.top()->resume();
			}

			this->_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->pause();
				}
			}
			this->_states.push(std::move(this->_newState));
			this->_states.top()->init();
			this->_isAdding = false;
		}
	}
	StateRef& StateHandler::GetActiveState()
	{
		return this->_states.top();
	}
