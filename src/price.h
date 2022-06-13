//
// Created by Arne on 13.06.22.
//

#ifndef MAARA_PRICE_H
#define MAARA_PRICE_H
namespace maara {
  class Price {
  public:
      explicit Price(double value): value_(value) {
      }

      /**
       * Returns the current value.
       *
       * @return double
       */
      inline const double value() const {
          return this->value_;
      };

  private:
      double value_;
  };
};
#endif //MAARA_PRICE_H
