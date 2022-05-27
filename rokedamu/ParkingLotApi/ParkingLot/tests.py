from django.test import TestCase

# pm test ParkingLot.tests.TestParkingLot


class TestParkingLot(TestCase):
    def test_bob(self):
        self.assertEquals("bob", "bob")
