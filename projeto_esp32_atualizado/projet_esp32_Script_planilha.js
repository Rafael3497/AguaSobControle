function deleteOldTriggers() {
    // Obtém todos os gatilhos do projeto
    var triggers = ScriptApp.getProjectTriggers();
    
    // Itera sobre todos os gatilhos
    for (var i = 0; i < triggers.length; i++) {
      // Verifica se o nome do gatilho corresponde ao que você deseja remover
      // Neste caso, estamos assumindo que você quer remover todos os gatilhos relacionados à função 'getAllData'
      if (triggers[i].getHandlerFunction().includes('getAllData')) {
        // Remove o gatilho
        ScriptApp.deleteTrigger(triggers[i]);
      }
    }
  }
  
  function createUpdateTrigger() {
    // Cria um novo gatilho de tempo para chamar a função getAllData a cada 15 minutos
    ScriptApp.newTrigger('getAllData')
    .timeBased()
    .everyMinutes(30) // Executa a função a cada 30 minutos
    .create();
  }
  
  function getAllData() {
    var ss = SpreadsheetApp.getActiveSpreadsheet();
    var sheet = ss.getActiveSheet();
  
    var firebaseUrl = "https://aguasobcontrole-a84e8-default-rtdb.firebaseio.com/SensorVazao";
    var base = FirebaseApp.getDatabaseByUrl(firebaseUrl);
  
    var dataSet = [base.getData()];
    var rows = [], data;
  
    for (i = 0; i < dataSet.length; i++) {
      data = dataSet[i];
      var in_time = Utilities.formatDate(new Date(), "America/Sao_Paulo", "HH:mm:ss");
      var in_date = Utilities.formatDate(new Date(), "America/Sao_Paulo", "yyyy-MM-dd");
      rows.push([data.VolumeVazao, data.TaxaDeFluxo, in_time, in_date]);
    }
  
    var dataRange = sheet.getRange(sheet.getLastRow() + 1, 1, rows.length, rows[0].length);
    dataRange.setValues(rows);
  }
  
  // Chama a função deleteOldTriggers para remover gatilhos antigos
  deleteOldTriggers();
  
  // Chama a função createUpdateTrigger para criar o novo gatilho
  createUpdateTrigger();
  