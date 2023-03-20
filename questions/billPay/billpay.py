from datetime import datetime
from unittest import TestCase, main as unitTestMain


class Bill():
    def __init__(self, date):
        self.date = date

    def get_payment_date(self):
        raise NotImplementedError()


class TestingDates:
    DATE_FORMAT = '%m/%d/%y'

    THURSDAY = datetime.strptime('10/18/18', DATE_FORMAT)
    FRIDAY = datetime.strptime('10/19/18', DATE_FORMAT)
    SATURDAY = datetime.strptime('10/20/18', DATE_FORMAT)
    SUNDAY = datetime.strptime('10/21/18', DATE_FORMAT)
    NEXT_MONDAY = datetime.strptime('10/22/18', DATE_FORMAT)
    NEXT_TUESDAY = datetime.strptime('10/23/18', DATE_FORMAT)
    NEXT_WEDNESDAY = datetime.strptime('10/24/18', DATE_FORMAT)


class TestBill(TestCase):

    def test_returns_payment_date(self):
        payment_date = Bill(TestingDates.THURSDAY).get_payment_date()
        self.assertEqual(TestingDates.THURSDAY, payment_date)


if __name__ == '__main__':
    unitTestMain()
