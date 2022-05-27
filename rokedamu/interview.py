import requests

import numpy as np


def main():
    version = requests.get("https://www.howsmyssl.com/a/check").json()["tls_version"]
    if version < "TLS 1.2":
        url = "http://pyfound.blogspot.com/2017/01/time-to-upgrade-your-python-tls-v12.html"
        print(
            f"Error: The Stripe API requires TLS version 1.2, you are running {version}"
            f"\n\nPlease see {url} for instructions to update your environment."
        )
        exit(1)
    print("TLS 1.2 supported, no action required.")


def generate_bob():
    return "bob"


if __name__ == "__main__":
    main()
