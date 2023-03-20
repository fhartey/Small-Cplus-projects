const { expect } = require("chai");
const Mocha = require("mocha");
const mocha = new Mocha();
mocha.suite.emit("pre-require", this, "solution", mocha); // Bit of a hack, sorry!


class Bill {

  constructor(date) {
    this.date = date;
  }

  get paymentDate() {
    return null;
  }
}


const TestingDates = {
  wednesday: new Date("01/02/2019"),
  thursday: new Date("01/03/2019"),
  friday: new Date("01/04/2019"),
  saturday: new Date("01/05/2019"),
  sunday: new Date("01/06/2019"),
  nextMonday: new Date("01/07/2019"),
  nextTuesday: new Date("01/08/2019")
};


describe("Bill", () => {
  describe("paymentDate", () => {
    it("Should return the payment date", () => {
      expect(new Bill(TestingDates.wednesday).paymentDate.toString()).to.equal(TestingDates.wednesday.toString());
    });
  })
});


mocha.run();
