#include <iostream>
#include <blt/parse/argparse_v2.h>
#include <blt/std/types.h>
#include <blt/std/random.h>

// 40 hours a week max
constexpr blt::i32 INDIVIDUAL_SHIFTS_PER_WEEK = 5;
// 4 people working at the park
constexpr blt::i32 PEOPLE_TO_SCHEDULE = 4;
constexpr blt::i32 TOTALS_SHIFTS_PER_WEEK = INDIVIDUAL_SHIFTS_PER_WEEK * PEOPLE_TO_SCHEDULE;
constexpr blt::i32 POPULATION_SIZE = 100;

// need to do some kind of route building algorithm?

blt::random::random_t& get_random()
{
	thread_local blt::random::random_t random{691};
	return random;
}

enum class shift_t : blt::u8
{
	OFF, AMs, PMs
};

struct weekday_t
{
	enum value_t : blt::u8
	{
		SATURDAY,
		SUNDAY,
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY
	};

	weekday_t() = default;

	constexpr weekday_t(const value_t value) : value(value) // NOLINT
	{}

	constexpr operator value_t() const // NOLINT
	{
		return value;
	}

	explicit operator bool() const = delete;

	constexpr bool operator==(const weekday_t a) const
	{
		return value == a.value;
	}

	constexpr bool operator!=(const weekday_t a) const
	{
		return value != a.value;
	}

	[[nodiscard]] bool is_weekend() const
	{
		switch (value)
		{
			case SATURDAY:
			case SUNDAY:
				return true;
			case MONDAY:
			case TUESDAY:
			case WEDNESDAY:
			case THURSDAY:
			case FRIDAY:
				return false;
		}
		BLT_UNREACHABLE;
	}

private:
	value_t value;
};

struct schedule_t
{
	std::array<shift_t, TOTALS_SHIFTS_PER_WEEK> shifts;
};

class shift_solver_t
{
public:


private:
};

int main()
{
	std::cout << "Hello World!" << std::endl;
}
