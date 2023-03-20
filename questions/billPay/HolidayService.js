class HolidayService {
  holidays;

  constructor() {
    this.holidays = [];
  }

  addHoliday(date) {
    this.holidays.push(date);
  }

  isHoliday(date) {
    return this.holidays.some(holiday => holiday.toString() === date.toString());
  }
}

describe("Holiday Service", function() {
  describe("the addHoliday", function() {
    it("should add holidays", function() {
      var holidays = new HolidayService();
      holidays.addHoliday(dates.wednesday);

      expect(holidays.isHoliday(dates.wednesday)).to.be.true
    });
  });
  describe("the isHoliday", function() {
    it("should not return a holiday if it hasn'nt been added", function() {
      const holidays = new HolidayService();
      holidays.addHoliday(dates.wednesday);

      expect(holidays.isHoliday(dates.thursday)).to.be.false
    });
  });
});