(function() {
  var terminal = document.getElementById('terminal'),
      clear = document.getElementById('clear'),
      restart = document.getElementById('restart'),
      ws = null,
      reconnectTimeout = null,
      prefix = '';

  function _connect() {
    if (!ws || ws.readyState === WebSocket.CLOSED) {
      try {
        ws = new WebSocket('ws://' + window.location.hostname + '/ws');
        ws.onopen = _onOpen;
        ws.onmessage = _onMessage;
        ws.onclose = _onClose;
      } catch (e) {
        _onClose();
      }
    }
  }

  function _onOpen() {
    clearTimeout(reconnectTimeout);
  }

  function _onClose(e) {
    var code = e && e.code || 1012;
    ws = null;
    if (code > 1000) {
      reconnectTimeout = setTimeout(_connect, 1000);
    }
  }

  function _onMessage(message) {
    var data = message && message.data;
    if (data) {
      data = prefix + data;

      if (data.endsWith("\n")) {
        prefix = "\n";
        data = data.substr(0, data.length - 1);
      } else {
        prefix = '';
      }

      terminal.value += data;
      terminal.scrollTop = terminal.scrollHeight;
    }
  }

  clear.addEventListener('click', function(e) {
    terminal.value = '';
    prefix = '';
  });

  restart.addEventListener('click', function(e) {
    var xhr = new XMLHttpRequest();
    xhr.open('POST', '/restart', true);
    xhr.send(null);
  });

  _connect();
})();
