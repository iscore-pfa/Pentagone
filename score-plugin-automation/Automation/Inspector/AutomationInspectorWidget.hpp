#pragma once
#include <Automation/AutomationModel.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>

#include <score/command/Dispatchers/CommandDispatcher.hpp>


#include <Color/GradientModel.hpp>
#include <Metronome/MetronomeModel.hpp>
#include <Spline/SplineModel.hpp>
#include <Polygon/PolygonModel.hpp>
#include <Pentagone/PentagoneModel.hpp>
#include <Hexagon/HexagonModel.hpp>
#include <Square/SquareModel.hpp>
#include <Circle/CircleModel.hpp>
#include <Infinite/InfiniteModel.hpp>
#include <Heart/HeartModel.hpp>
#include <Rectangle/RectangleModel.hpp>
#include <Triangle/TriangleModel.hpp>


class QLabel;
class QWidget;
class QCheckBox;

namespace score
{
struct DocumentContext;
}
namespace State
{
struct Address;
class UnitWidget;
}
namespace Device
{
struct FullAddressAccessorSettings;
class AddressAccessorEditWidget;
}
namespace Explorer
{
class DeviceExplorerModel;
}
class QDoubleSpinBox;

namespace Automation
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Automation::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_minValueChanged();
  void on_maxValueChanged();
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};
  QDoubleSpinBox *m_minsb{}, *m_maxsb{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Gradient
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Gradient::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_tweenChanged();

  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Spline
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Spline::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Polygon
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Polygon::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Pentagone
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Pentagone::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Hexagon
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Hexagon::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Square
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Square::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Circle
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Circle::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Infinite
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Infinite::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Heart
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Heart::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Rectangle
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Rectangle::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}

namespace Triangle
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Triangle::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);
  void on_tweenChanged();

  Device::AddressAccessorEditWidget* m_lineEdit{};
  QCheckBox* m_tween{};

  CommandDispatcher<> m_dispatcher;
};
}


namespace Metronome
{
class ProcessModel;
class InspectorWidget final
    : public Process::InspectorWidgetDelegate_T<Metronome::ProcessModel>
{
public:
  explicit InspectorWidget(
      const ProcessModel& object,
      const score::DocumentContext& context,
      QWidget* parent);

private:
  void on_addressChange(const Device::FullAddressAccessorSettings& newText);

  Device::AddressAccessorEditWidget* m_lineEdit{};

  CommandDispatcher<> m_dispatcher;
};
}
