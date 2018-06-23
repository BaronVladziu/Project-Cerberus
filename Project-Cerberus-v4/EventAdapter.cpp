#include "EventAdapter.h"
#include "EventType.h"

EventType EventAdapter::translateEvent(const sf::Event & event) const
{
	switch (event.type)
	{
	case sf::Event::Closed:
		return EventType::WindowClosedEvent;
	case sf::Event::MouseButtonPressed:
		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			return EventType::LeftMouseButtonPressedEvent;
		case sf::Mouse::Right:
			return EventType::RightMouseButtonPressedEvent;
		}
		break;
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			return EventType::UpArrowPressedEvent;
		case sf::Keyboard::Down:
			return EventType::DownArrowPressedEvent;
		case sf::Keyboard::Right:
			return EventType::RightArrowPressedEvent;
		case sf::Keyboard::Left:
			return EventType::LeftArrowPressedEvent;

		case sf::Keyboard::Num1:
			return EventType::Nr1ButtonPressedEvent;
		case sf::Keyboard::Num2:
			return EventType::Nr2ButtonPressedEvent;
		case sf::Keyboard::Num3:
			return EventType::Nr3ButtonPressedEvent;
		case sf::Keyboard::Num4:
			return EventType::Nr4ButtonPressedEvent;
		case sf::Keyboard::Num5:
			return EventType::Nr5ButtonPressedEvent;
		case sf::Keyboard::Num6:
			return EventType::Nr6ButtonPressedEvent;
		case sf::Keyboard::Num7:
			return EventType::Nr7ButtonPressedEvent;
		case sf::Keyboard::Num8:
			return EventType::Nr8ButtonPressedEvent;
		case sf::Keyboard::Num9:
			return EventType::Nr9ButtonPressedEvent;
		case sf::Keyboard::Num0:
			return EventType::Nr0ButtonPressedEvent;
		case sf::Keyboard::Dash:
			return EventType::MinusButtonPressedEvent;
		case sf::Keyboard::Equal:
			return EventType::PlusButtonPressedEvent;

		case sf::Keyboard::Escape:
			return EventType::EscButtonPressedEvent;
		case sf::Keyboard::Tab:
			return EventType::TabButtonPressedEvent;
		case sf::Keyboard::LShift:
			return EventType::ShiftButtonPressedEvent;
		case sf::Keyboard::RShift:
			return EventType::ShiftButtonPressedEvent;
		case sf::Keyboard::LControl:
			return EventType::CtrlButtonPressedEvent;
		case sf::Keyboard::RControl:
			return EventType::CtrlButtonPressedEvent;
		case sf::Keyboard::LAlt:
			return EventType::AltButtonPressedEvent;
		case sf::Keyboard::RAlt:
			return EventType::AltButtonPressedEvent;
		case sf::Keyboard::Space:
			return EventType::SpaceButtonPressedEvent;

		case sf::Keyboard::Q:
			return EventType::QButtonPressedEvent;
		case sf::Keyboard::W:
			return EventType::WButtonPressedEvent;
		case sf::Keyboard::E:
			return EventType::EButtonPressedEvent;
		case sf::Keyboard::R:
			return EventType::RButtonPressedEvent;
		case sf::Keyboard::T:
			return EventType::TButtonPressedEvent;
		case sf::Keyboard::Y:
			return EventType::YButtonPressedEvent;
		case sf::Keyboard::U:
			return EventType::UButtonPressedEvent;
		case sf::Keyboard::I:
			return EventType::IButtonPressedEvent;
		case sf::Keyboard::O:
			return EventType::OButtonPressedEvent;
		case sf::Keyboard::P:
			return EventType::PButtonPressedEvent;
		case sf::Keyboard::A:
			return EventType::AButtonPressedEvent;
		case sf::Keyboard::S:
			return EventType::SButtonPressedEvent;
		case sf::Keyboard::D:
			return EventType::DButtonPressedEvent;
		case sf::Keyboard::F:
			return EventType::FButtonPressedEvent;
		case sf::Keyboard::G:
			return EventType::GButtonPressedEvent;
		case sf::Keyboard::H:
			return EventType::HButtonPressedEvent;
		case sf::Keyboard::J:
			return EventType::JButtonPressedEvent;
		case sf::Keyboard::K:
			return EventType::KButtonPressedEvent;
		case sf::Keyboard::L:
			return EventType::LButtonPressedEvent;
		case sf::Keyboard::Z:
			return EventType::ZButtonPressedEvent;
		case sf::Keyboard::X:
			return EventType::XButtonPressedEvent;
		case sf::Keyboard::C:
			return EventType::CButtonPressedEvent;
		case sf::Keyboard::V:
			return EventType::VButtonPressedEvent;
		case sf::Keyboard::B:
			return EventType::BButtonPressedEvent;
		case sf::Keyboard::N:
			return EventType::NButtonPressedEvent;
		case sf::Keyboard::M:
			return EventType::MButtonPressedEvent;

		case sf::Keyboard::Return:
			return EventType::ReturnButtonPressedEvent;
		}
	}
	return EventType::UnknownEvent;
}

EventAdapter::EventAdapter()
{}
EventType EventAdapter::pollEvent(sf::RenderWindow & window)
{
	if (window.pollEvent(_event))
	{
		return translateEvent(_event);
	}
	return EventType::NoMoreEvents;
}

EventAdapter::~EventAdapter()
{}