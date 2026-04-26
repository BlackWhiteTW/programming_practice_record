<?php
function h($value)
{
  return htmlspecialchars((string)$value, ENT_QUOTES, 'UTF-8');
}

$hobbyMap = [
  "1" => "游泳",
  "2" => "慢跑",
  "3" => "打網球",
  "4" => "打籃球",
  "5" => "爬山"
];

$isPost = $_SERVER['REQUEST_METHOD'] === 'POST';

$user = $_POST['user'] ?? '';
$year = $_POST['year'] ?? '75';
$month = $_POST['month'] ?? '5';
$day = $_POST['day'] ?? '29';
$sex = $_POST['sex'] ?? '1';
$hobbies = (isset($_POST['hobby']) && is_array($_POST['hobby'])) ? $_POST['hobby'] : ['1', '3', '5'];
$mail = $_POST['mail'] ?? '';
$content = $_POST['content'] ?? '';

$resultHobbyText = [];
foreach ($hobbies as $hobby) {
  if (isset($hobbyMap[$hobby])) {
    $resultHobbyText[] = $hobbyMap[$hobby];
  }
}
?>
<!DOCTYPE html>
<html lang="zh-Hant">
<head>
  <meta charset="UTF-8">
  <title>表單傳送</title>
  <style>

    .submit-cell {
      text-align: center;
    }

    return_table{
      width: 500px;
      border: 1px solid #000;
      border-collapse: collapse;
    }
    .return_input{
      width: 315px;
      color : blue; 
    }
    

    .result-title {
      font-weight: bold;
      margin-bottom: 10px;
    }
  </style>
</head>
<body>

<div class="block">
  <h2>會員基本資料填寫</h2>
  <form name="MyForm1" action="" method="POST" enctype="multipart/form-data">
    <table border="1">
      <tbody>
      <tr>
        <td class="label">姓名：</td>
        <td><input type="text" name="user" size="20" maxlength="10" value="<?= h($user) ?>"></td>
      </tr>
      <tr>
        <td class="label">生日：</td>
        <td>
          <select name="year" size="1">
            <?php for ($i = 60; $i <= 80; $i++): ?>
              <option value="<?= $i ?>" <?= (string)$i === (string)$year ? 'selected' : '' ?>><?= $i ?></option>
            <?php endfor; ?>
          </select> 年

          <select name="month" size="1">
            <?php for ($i = 1; $i <= 12; $i++): ?>
              <option value="<?= $i ?>" <?= (string)$i === (string)$month ? 'selected' : '' ?>><?= $i ?></option>
            <?php endfor; ?>
          </select> 月

          <select name="day" size="1">
            <?php for ($i = 1; $i <= 31; $i++): ?>
              <option value="<?= $i ?>" <?= (string)$i === (string)$day ? 'selected' : '' ?>><?= $i ?></option>
            <?php endfor; ?>
          </select> 日
        </td>
      </tr>
      <tr>
        <td class="label">性別：</td>
        <td>
          <span class="radio-group">
            <label><input type="radio" name="sex" value="1" <?= $sex === '1' ? 'checked' : '' ?>>男生</label>
            <label><input type="radio" name="sex" value="2" <?= $sex === '2' ? 'checked' : '' ?>>女生</label>
          </span>
        </td>
      </tr>
      <tr>
        <td class="label">興趣：</td>
        <td>
          <span class="checkbox-group">
            <?php foreach ($hobbyMap as $id => $text): ?>
              <label><input type="checkbox" name="hobby[]" value="<?= $id ?>" <?= in_array($id, $hobbies, true) ? 'checked' : '' ?>><?= $text ?></label>
            <?php endforeach; ?>
          </span>
        </td>
      </tr>
      <tr>
        <td class="label">E-mail：</td>
        <td><input type="text" name="mail" size="20" maxlength="40" value="<?= h($mail) ?>"></td>
      </tr>
      <tr>
        <td class="label">照片上傳：</td>
        <td><input type="file" name="Myfile"></td>
      </tr>
      <tr>
        <td class="label">自我介紹：</td>
        <td><textarea name="content" rows="8" cols="40"><?= h($content) ?></textarea></td>
      </tr>
      <tr>
        <td colspan="2" class="submit-cell"><input type="submit" value="送出資料"></td>
      </tr>
      </tbody>
    </table>
  </form>
</div>

<?php if ($isPost): ?>
  <div class="block">
    <div class="result-title">會員基本資料填寫</div>
    <table border="1" class="return_table">
      <tbody>
      <tr>
        <td class="label">姓名：</td>
        <td class="return_input"  ><?= h($user) ?></td>
      </tr>
      <tr>
        <td class="label">生日：</td>
        <td class="return_input"><?= h($year) ?>年<?= h($month) ?>月<?= h($day) ?>日</td>
      </tr>
      <tr>
        <td class="label">性別：</td>
        <td class="return_input"><?= $sex === '2' ? '女生' : '男生' ?></td>
      </tr>
      <tr>
        <td class="label">興趣：</td>
        <td class="return_input"><?= h(implode(' ', $resultHobbyText)) ?></td>
      </tr>
      <tr>
        <td class="label">E-mail：</td>
        <td class="return_input"><?= h($mail) ?></td>
      </tr>
      <tr>
        <td class="label">自我介紹：</td>
        <td class="return_input"><?= nl2br(h($content)) ?></td>
      </tr>
      <tr>
        <td colspan="2" class="submit-cell"><input type="button" value="確定送出" onclick="window.scrollTo({top: 0, behavior: 'smooth'});"></td>
      </tr>
      </tbody>
    </table>
  </div>
<?php endif; ?>

</body>
</html>
