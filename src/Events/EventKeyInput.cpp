#include "Bubblewrap/Events/EventKeyInput.hpp"
namespace Bubblewrap
{
	namespace Events
	{

		Key TranslateKey( sf::Keyboard::Key key )
		{
			switch ( key )
			{
			case sf::Keyboard::Key::Unknown: return Bubblewrap::Events::Key::Unknown; break;
			case sf::Keyboard::Key::A: return Bubblewrap::Events::Key::A; break;
			case sf::Keyboard::Key::B: return Bubblewrap::Events::Key::B; break;
			case sf::Keyboard::Key::C: return Bubblewrap::Events::Key::C; break;
			case sf::Keyboard::Key::D: return Bubblewrap::Events::Key::D; break;
			case sf::Keyboard::Key::E: return Bubblewrap::Events::Key::E; break;
			case sf::Keyboard::Key::F: return Bubblewrap::Events::Key::F; break;
			case sf::Keyboard::Key::G: return Bubblewrap::Events::Key::G; break;
			case sf::Keyboard::Key::H: return Bubblewrap::Events::Key::H; break;
			case sf::Keyboard::Key::I: return Bubblewrap::Events::Key::I; break;
			case sf::Keyboard::Key::J: return Bubblewrap::Events::Key::J; break;
			case sf::Keyboard::Key::K: return Bubblewrap::Events::Key::K; break;
			case sf::Keyboard::Key::L: return Bubblewrap::Events::Key::L; break;
			case sf::Keyboard::Key::M: return Bubblewrap::Events::Key::M; break;
			case sf::Keyboard::Key::N: return Bubblewrap::Events::Key::N; break;
			case sf::Keyboard::Key::O: return Bubblewrap::Events::Key::O; break;
			case sf::Keyboard::Key::P: return Bubblewrap::Events::Key::P; break;
			case sf::Keyboard::Key::Q: return Bubblewrap::Events::Key::Q; break;
			case sf::Keyboard::Key::R: return Bubblewrap::Events::Key::R; break;
			case sf::Keyboard::Key::S: return Bubblewrap::Events::Key::S; break;
			case sf::Keyboard::Key::T: return Bubblewrap::Events::Key::T; break;
			case sf::Keyboard::Key::U: return Bubblewrap::Events::Key::U; break;
			case sf::Keyboard::Key::V: return Bubblewrap::Events::Key::V; break;
			case sf::Keyboard::Key::W: return Bubblewrap::Events::Key::W; break;
			case sf::Keyboard::Key::X: return Bubblewrap::Events::Key::X; break;
			case sf::Keyboard::Key::Y: return Bubblewrap::Events::Key::Y; break;
			case sf::Keyboard::Key::Z: return Bubblewrap::Events::Key::Z; break;
			case sf::Keyboard::Key::Num0: return Bubblewrap::Events::Key::Num0; break;
			case sf::Keyboard::Key::Num1: return Bubblewrap::Events::Key::Num1; break;
			case sf::Keyboard::Key::Num2: return Bubblewrap::Events::Key::Num2; break;
			case sf::Keyboard::Key::Num3: return Bubblewrap::Events::Key::Num3; break;
			case sf::Keyboard::Key::Num4: return Bubblewrap::Events::Key::Num4; break;
			case sf::Keyboard::Key::Num5: return Bubblewrap::Events::Key::Num5; break;
			case sf::Keyboard::Key::Num6: return Bubblewrap::Events::Key::Num6; break;
			case sf::Keyboard::Key::Num7: return Bubblewrap::Events::Key::Num7; break;
			case sf::Keyboard::Key::Num8: return Bubblewrap::Events::Key::Num8; break;
			case sf::Keyboard::Key::Num9: return Bubblewrap::Events::Key::Num9; break;
			case sf::Keyboard::Key::Escape: return Bubblewrap::Events::Key::Escape; break;
			case sf::Keyboard::Key::LControl: return Bubblewrap::Events::Key::LControl; break;
			case sf::Keyboard::Key::LShift: return Bubblewrap::Events::Key::LShift; break;
			case sf::Keyboard::Key::LAlt: return Bubblewrap::Events::Key::LAlt; break;
			case sf::Keyboard::Key::LSystem: return Bubblewrap::Events::Key::LSystem; break;
			case sf::Keyboard::Key::RControl: return Bubblewrap::Events::Key::RControl; break;
			case sf::Keyboard::Key::RShift: return Bubblewrap::Events::Key::RShift; break;
			case sf::Keyboard::Key::RAlt: return Bubblewrap::Events::Key::RAlt; break;
			case sf::Keyboard::Key::RSystem: return Bubblewrap::Events::Key::RSystem; break;
			case sf::Keyboard::Key::Menu: return Bubblewrap::Events::Key::Menu; break;
			case sf::Keyboard::Key::LBracket: return Bubblewrap::Events::Key::LBracket; break;
			case sf::Keyboard::Key::RBracket: return Bubblewrap::Events::Key::RBracket; break;
			case sf::Keyboard::Key::SemiColon: return Bubblewrap::Events::Key::SemiColon; break;
			case sf::Keyboard::Key::Comma: return Bubblewrap::Events::Key::Comma; break;
			case sf::Keyboard::Key::Period: return Bubblewrap::Events::Key::Period; break;
			case sf::Keyboard::Key::Quote: return Bubblewrap::Events::Key::Quote; break;
			case sf::Keyboard::Key::Slash: return Bubblewrap::Events::Key::Slash; break;
			case sf::Keyboard::Key::BackSlash: return Bubblewrap::Events::Key::BackSlash; break;
			case sf::Keyboard::Key::Tilde: return Bubblewrap::Events::Key::Tilde; break;
			case sf::Keyboard::Key::Equal: return Bubblewrap::Events::Key::Equal; break;
			case sf::Keyboard::Key::Dash: return Bubblewrap::Events::Key::Dash; break;
			case sf::Keyboard::Key::Space: return Bubblewrap::Events::Key::Space; break;
			case sf::Keyboard::Key::Return: return Bubblewrap::Events::Key::Return; break;
			case sf::Keyboard::Key::BackSpace: return Bubblewrap::Events::Key::BackSpace; break;
			case sf::Keyboard::Key::Tab: return Bubblewrap::Events::Key::Tab; break;
			case sf::Keyboard::Key::PageUp: return Bubblewrap::Events::Key::PageUp; break;
			case sf::Keyboard::Key::PageDown: return Bubblewrap::Events::Key::PageDown; break;
			case sf::Keyboard::Key::End: return Bubblewrap::Events::Key::End; break;
			case sf::Keyboard::Key::Home: return Bubblewrap::Events::Key::Home; break;
			case sf::Keyboard::Key::Insert: return Bubblewrap::Events::Key::Insert; break;
			case sf::Keyboard::Key::Delete: return Bubblewrap::Events::Key::Delete; break;
			case sf::Keyboard::Key::Add: return Bubblewrap::Events::Key::Add; break;
			case sf::Keyboard::Key::Subtract: return Bubblewrap::Events::Key::Subtract; break;
			case sf::Keyboard::Key::Multiply: return Bubblewrap::Events::Key::Multiply; break;
			case sf::Keyboard::Key::Divide: return Bubblewrap::Events::Key::Divide; break;
			case sf::Keyboard::Key::Left: return Bubblewrap::Events::Key::Left; break;
			case sf::Keyboard::Key::Right: return Bubblewrap::Events::Key::Right; break;
			case sf::Keyboard::Key::Up: return Bubblewrap::Events::Key::Up; break;
			case sf::Keyboard::Key::Down: return Bubblewrap::Events::Key::Down; break;
			case sf::Keyboard::Key::Numpad0: return Bubblewrap::Events::Key::Numpad0; break;
			case sf::Keyboard::Key::Numpad1: return Bubblewrap::Events::Key::Numpad1; break;
			case sf::Keyboard::Key::Numpad2: return Bubblewrap::Events::Key::Numpad2; break;
			case sf::Keyboard::Key::Numpad3: return Bubblewrap::Events::Key::Numpad3; break;
			case sf::Keyboard::Key::Numpad4: return Bubblewrap::Events::Key::Numpad4; break;
			case sf::Keyboard::Key::Numpad5: return Bubblewrap::Events::Key::Numpad5; break;
			case sf::Keyboard::Key::Numpad6: return Bubblewrap::Events::Key::Numpad6; break;
			case sf::Keyboard::Key::Numpad7: return Bubblewrap::Events::Key::Numpad7; break;
			case sf::Keyboard::Key::Numpad8: return Bubblewrap::Events::Key::Numpad8; break;
			case sf::Keyboard::Key::Numpad9: return Bubblewrap::Events::Key::Numpad9; break;
			case sf::Keyboard::Key::F1: return Bubblewrap::Events::Key::F1; break;
			case sf::Keyboard::Key::F2: return Bubblewrap::Events::Key::F2; break;
			case sf::Keyboard::Key::F3: return Bubblewrap::Events::Key::F3; break;
			case sf::Keyboard::Key::F4: return Bubblewrap::Events::Key::F4; break;
			case sf::Keyboard::Key::F5: return Bubblewrap::Events::Key::F5; break;
			case sf::Keyboard::Key::F6: return Bubblewrap::Events::Key::F6; break;
			case sf::Keyboard::Key::F7: return Bubblewrap::Events::Key::F7; break;
			case sf::Keyboard::Key::F8: return Bubblewrap::Events::Key::F8; break;
			case sf::Keyboard::Key::F9: return Bubblewrap::Events::Key::F9; break;
			case sf::Keyboard::Key::F10: return Bubblewrap::Events::Key::F10; break;
			case sf::Keyboard::Key::F11: return Bubblewrap::Events::Key::F11; break;
			case sf::Keyboard::Key::F12: return Bubblewrap::Events::Key::F12; break;
			case sf::Keyboard::Key::Pause: return Bubblewrap::Events::Key::Pause; break;

			}
			return Bubblewrap::Events::Key::Unknown;
		}
	}
}
