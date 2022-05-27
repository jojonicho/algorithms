from django.db import models

# Create your models here.
class ParkingLot(models.Model):
    lot_name = models.CharField(max_length=100)
    lot_location = models.CharField(max_length=100)
    lot_capacity = models.IntegerField()
    lot_price = models.IntegerField()
    lot_status = models.CharField(max_length=100)
    lot_owner = models.CharField(max_length=100)
    lot_contact = models.CharField(max_length=100)
    lot_image = models.CharField(max_length=100)
    lot_description = models.CharField(max_length=100)
    lot_created = models.DateTimeField(auto_now_add=True)
    lot_modified = models.DateTimeField(auto_now=True)
    lot_active = models.BooleanField(default=True)
    lot_slug = models.SlugField(max_length=100, unique=True)
    lot_image = models.ImageField(upload_to="images/")

    def __str__(self):
        return self.lot_name
