#include<iostream>
class Log {
public:
	enum Level { //√∂æŸ¿‡
		LevelError = 0, LevelWarning = 1, LevelInfo = 2
	};
private:
	Level m_Loglevel = LevelWarning;
public:
	void SetLevel(Level level) {
		m_Loglevel = level;
	}
	void Error(const char* message) {
		std::cout << "[ERROR]:" << message << std::endl;
	}
	void Warn(const char* message) {
		std::cout << "[WARN]:" << message << std::endl;
	}
	void Info(const char* message) {
		std::cout << "[INFO]:" << message << std::endl;
	}
};

void Sett() {
	Log a;
	a.SetLevel(a.LevelInfo);
	a.Info("The situation is Info.");
}