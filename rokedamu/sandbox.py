from collections import OrderedDict

# dictionary sorted by key lexicographically


class SortedDict(dict):
    def __init__(self, *args, **kwargs):
        super(SortedDict, self).__init__(*args, **kwargs)
        self.keyOrder = sorted(super(SortedDict, self).keys())

    def __setitem__(self, key, value):
        super(SortedDict, self).__setitem__(key, value)
        if key not in self.keyOrder:
            self.keyOrder.append(key)

    def __delitem__(self, key):
        super(SortedDict, self).__delitem__(key)
        self.keyOrder.remove(key)

    def __iter__(self):
        for key in self.keyOrder:
            yield key

    def __reversed__(self):
        for key in reversed(self.keyOrder):
            yield key

    def pop(self, k, *args):
        result = super(SortedDict, self).pop(k, *args)
        try:
            self.keyOrder.remove(k)
        except ValueError:
            # Key wasn't in the dictionary in the first place. No problem.
            pass
        return result

    def popitem(self):
        result = super(SortedDict, self).popitem()
        self.keyOrder.remove(result[0])
        return result

    def items(self):
        return zip(self.keyOrder, self.values())

    def iteritems(self):
        for key in self.keyOrder:
            yield key, super(SortedDict, self).__getitem__(key)

    def keys(self):
        return self.keyOrder[:]

    def iterkeys(self):
        return iter(self.keyOrder)

    def values(self):
        return [super(SortedDict, self).__getitem__(k) for k in self.keyOrder]

    def itervalues(self):
        for key in self.keyOrder:
            yield super(SortedDict, self).__getitem__(key)

    def update(self, dict_):
        for k, v in dict_.items():
            self.__setitem__(k, v)

    def setdefault(self, key, default):
        if key not in self.keyOrder:
            self.keyOrder.append(key)
        return super(SortedDict, self).setdefault(key, default)

    def value_for_index(self, index):
        """Returns the value of the item at the given zero-based index."""
        return self[self.keyOrder[index]]

    def insert(self, index, key, value):
        """Inserts the key, value pair before the item with the given index."""
        if key in self.keyOrder:
            n = self.keyOrder.index(key)
            del self.keyOrder[n]
            if n < index:
                index -= 1
        self.keyOrder.insert(index, key)
        super(SortedDict, self).__setitem__(key, value)

    def copy(self):
        """Returns a copy of this object."""
        # This way of initializing the copy means it works for subclasses, too.
        obj = self.__class__(self)
        obj.keyOrder = self.keyOrder[:]
        return obj

    def __repr__(self):
        """
        Replaces the normal dict.__repr__ with a version that returns the keys
        in their sorted order.
        """
        return "{%s}" % ", ".join(["%r: %r" % (k, v) for k, v in self.items()])

    def clear(self):
        super(SortedDict, self).clear()
        self.keyOrder = []


class ManualComment:
    def __init__(self, id: int, text: str) -> None:
        self.id: int = id
        self.text: int = text

    def __repr__(self) -> str:
        return f"id={self.id} text={self.text}"

    def __eq__(self, o: object) -> bool:
        if o.__class__ is self.__class__:
            return (self.id, self.text) == (o.id, o.text)
        return False


from dataclasses import dataclass, astuple, asdict, field


@dataclass(frozen=True, order=True)
class Data:
    x: int
    y: int
    a: int = field(default=0)


def test_dataclass():
    data = Data(6, 9)
    print(data)
    print(astuple(data))
    print(asdict(data))


from urllib import request


def urllib_request():
    URL = "https://pokeapi.co/api/v2/pokemon/ditto"
    res = request.urlopen(URL)
    data = json.loads(res.read())
    pprint(data["stats"])


def requests_request():
    from requests import get

    URL = "https://pokeapi.co/api/v2/pokemon/ditto"
    res = get(URL)
    data = json.loads(res.text)
    pprint(data["stats"])


if __name__ == "__main__":
    import json
    from pprint import pprint

    urllib_request()
    requests_request()
    test_dataclass()
    # url = "http://www.google.com/finance/info?infotype=infoquoteall&q=NASDAQ:GOOG"
    # response = request.urlopen(url)
    # content = response.read()
    # encoding = response.info().get_content_charset("utf-8")
    # data = json.loads(content.decode(encoding))
    # quote = data[0]
    # print(quote["Index"])
    # print(quote["Name"])
    # print(quote["PrevClose"])
    # print(quote["Open"])
    # print(quote["Change"])
    # print(quote["Change_pct"])
    # print(quote["Volume"])
    # print(quote["Market_cap"])
    # print(quote["PE_ratio"])
    # print(quote["EPS_estimate_current_year"])
    # print(quote["EPS_estimate_next_year"])
    # print(quote["EPS_estimate_next_quarter"])
    # print(quote["EPS_estimate_next_month"])
    # print(quote["EPS_estimate_current_year"])
    # print(quote["EPS_estimate_current_quarter"])
    # print(quote["EPS_estimate_current_month"])
    # print(quote["EPS_estimate_current_year"])
    # print(quote["EPS_estimate_next_year"])
    # print(quote["EPS_estimate_next_quarter"])
    # print(quote["EPS_estimate_next_month"])
    # print(quote["EPS_estimate_next_year"])
    # print(quote["EPS_estimate_next_quarter"])
    # print(quote["EPS_estimate_next_month"])
