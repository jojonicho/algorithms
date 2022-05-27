from utils import check_car_id_in_parking_lot, check_parking_lot_error
from fastapi import FastAPI
from dataclass import CarDC, ParkingLotDC, ParkingLotLeaveDC
from services import ParkingLotService

app = FastAPI()

service = ParkingLotService()


@app.get("/")
def get_base():
    parking_lot = service.get_parking_lot()
    error = check_parking_lot_error(parking_lot)
    if error:
        return error

    if parking_lot is None:
        return {"message": "No parking lot available"}
    return parking_lot


@app.post("/")
def post_base(parking_lot_dc: ParkingLotDC):
    return service.create_parking_lot(capacity=parking_lot_dc.capacity)


@app.get("/cars/{color}")
def get_by_color(color: str):
    return service.get_parking_slots_by_color(color=color)


@app.post("/park")
def post_park(car_dc: CarDC):
    parking_lot = service.get_parking_lot()
    error = check_parking_lot_error(parking_lot)
    if error:
        return error
    return service.park(car_dc)


@app.post("/leave")
def post_leave(dc: ParkingLotLeaveDC):
    parking_lot = service.get_parking_lot()
    error = check_parking_lot_error(parking_lot)
    if error:
        return error
    error = check_car_id_in_parking_lot(parking_lot, dc.slot_id)
    if error:
        return error

    service.leave(dc.slot_id)
    return {"message": f"Slot number {dc.slot_id} is free"}
