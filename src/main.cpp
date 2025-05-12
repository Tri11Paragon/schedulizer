#include <iostream>
#include <blt/parse/argparse_v2.h>
#include <blt/std/types.h>
#include <blt/std/random.h>

constexpr blt::i32 SHIFTS_PER_WEEK = 5;
constexpr blt::i32 POPULATION_SIZE = 100;

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

	[[nodiscard]] std::vector<shift_t>& available_shifts() const
	{
		thread_local std::vector<shift_t> shifts;

		shifts.clear();
		if (is_weekend())
		{
			constexpr std::array weekend_shifts = {shift_t::AMs, shift_t::PMs, shift_t::AMs, shift_t::PMs};
			shifts.insert(shifts.end(), weekend_shifts.begin(), weekend_shifts.end());
			return shifts;
		} else
		{

		}

		return shifts;
	}

private:
	value_t value;
};

struct placement_t
{
	shift_t shift;
	bool invariant;

	explicit placement_t(const shift_t shift, const bool invariant = false) : shift{shift}, invariant{invariant}
	{}
};

struct day_t
{
	placement_t brett;
	placement_t kayda;
	placement_t tim;
	placement_t braeden;

	weekday_t day;

	day_t(const placement_t& brett, const placement_t& kayda, const placement_t& tim, const placement_t& braeden,
		const weekday_t day): brett{brett}, kayda{kayda}, tim{tim}, braeden{braeden}, day{day}
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
	static day_t generate_random_day(const weekday_t day)
	{
		auto& random = get_random();
		std::array<placement_t, 3> placements{};
		if (days_require_pair(day))
		{} else
		{}
	}

private:
};

int main()
{
	std::cout << "Hello World!" << std::endl;
}
