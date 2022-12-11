import 'package:flutter/material.dart';

void main() => runApp(const RobotControlApp());

class RobotControlApp extends StatelessWidget {
  const RobotControlApp({super.key});

  static const String _title = 'Robot control';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: _title,
      home: Scaffold(
        appBar: AppBar(title: const Text(_title)),
        body: const ControlWidget(),
      ),
    );
  }
}

class ControlWidget extends StatefulWidget {
  const ControlWidget({super.key});

  @override
  State<ControlWidget> createState() => _ControlWidgetState();
}

class _ControlWidgetState extends State<ControlWidget> {
  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      children: [
        VerticalSliderWidget(),
        VerticalSliderWidget(),
      ],
    );
  }
}

class VerticalSliderWidget extends StatefulWidget {
  const VerticalSliderWidget({super.key});

  @override
  State<VerticalSliderWidget> createState() => _VerticalSliderWidgetState();
}

class _VerticalSliderWidgetState extends State<VerticalSliderWidget> {
  double _currentSliderValue = 0;

  @override
  Widget build(BuildContext context) {
    return RotatedBox(
      quarterTurns: 3,
      child: Slider(
        value: _currentSliderValue,
        max: 100,
        min: -100,
        divisions: 20,
        label: _currentSliderValue.round().toString(),
        onChanged: (double value) {
          setState(() {
            _currentSliderValue = value;
          });
      },
    ));
  }
}
