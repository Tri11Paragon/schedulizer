#include <iostream>
#include <blt/parse/argparse_v2.h>
#include <blt/std/types.h>
#include <blt/std/random.h>

constexpr blt::i32 SHIFTS_PER_WEEK = 5;
constexpr blt::i32 POPULATION_SIZE = 100;

enum class shift_t : blt::u8
{
	NONE, AMs, PMs
};

enum class weekday_t : blt::u8
{
	SATURDAY,
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY
};

bool days_require_pair(const weekday_t day)
{
	switch (day)
	{
		case weekday_t::SATURDAY:
		case weekday_t::SUNDAY:
			return true;
		case weekday_t::MONDAY:
		case weekday_t::TUESDAY:
		case weekday_t::WEDNESDAY:
		case weekday_t::THURSDAY:
		case weekday_t::FRIDAY:
			return false;
	}
	BLT_UNREACHABLE;
}

struct placement_t
{
	shift_t shift;
	bool invariant;

	explicit placement_t(const shift_t shift, const bool invariant = false) : shift{shift}, invariant{invariant}
	{}
};

struct day_t
{
	placement_t brett{shift_t::PMs, true};
	placement_t kayda;
	placement_t tim;
	placement_t braeden;

	weekday_t day;

	[[nodiscard]] bool days_require_pair() const
	{
		return ::days_require_pair(day);
	}

	day_t(const placement_t& kayda, const placement_t& tim, const placement_t& braeden, const weekday_t day) : kayda{kayda},
																																tim{tim},
																																braeden{braeden},
																																day{day}
	{}
};

struct week_t
{
	day_t days[7];

	explicit week_t(const day_t days[7]): days{}
	{
		std::memcpy(this->days, days, sizeof(day_t) * 7);
	}
};

class shift_solver_t
{
public:
	static placement_t

	static day_t generate_random_day(const weekday_t day)
	{
		auto& random = get_random();
		std::array<placement_t, 3> placements{};
		if (days_require_pair(day))
		{

		} else
		{

		}
	}

	static blt::random::random_t& get_random()
	{
		thread_local blt::random::random_t random{691};
		return random;
	}
private:
};

int main()
{
	std::cout << "Hello World!" << std::endl;
}
