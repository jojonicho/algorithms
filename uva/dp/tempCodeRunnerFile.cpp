 (c == 'F') {
      seg.upd2(a, b, BUC);
    } else if (c == 'E') {
      seg.upd2(a, b, BAR);
    } else if (c == 'I') {
      seg.upd2(a, b, INV);
    } else {
      cout << ++nQuery << ": " << seg.qry(a, b) << en;
    }