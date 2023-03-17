from datetime import datetime
from unittest import TestCase

class HolidayService:

    def __init__(self):
        self._holidays = set()

    def set_holiday(self, date):
        self._holidays.add(date)

    def is_holiday(self, date):
        return date in self._holidays


class TestHolidayService(TestCase):

    def test_notifies_when_date_is_holiday(self):
        holiday = datetime.strptime("01/02/2019", "%m/%d/%Y")
        
        holiday_service = HolidayService()
        holiday_service.set_holiday(holiday)
        
        self.assertTrue(holiday_service.is_holiday(holiday))
        
    def test_notifies_when_date_is_not_holiday(self):
        any_day = datetime.strptime("01/02/2019", "%m/%d/%Y")
        
        holiday_service = HolidayService()
        
        self.assertFalse(holiday_service.is_holiday(any_day))