defmodule ApiDemo.Api.V1.SubscriberView do
  use ApiDemo.Web, :view

  def render("index.json", %{subscribers: subscribers}) when is_list(subscribers) do
    format subscribers, []
  end

  def render("show.json", %{subscriber: subscriber}) when is_list(subscriber) do
    format subscriber, []
  end

  def render("show.json", %{subscriber: subscriber}) when is_list(subscriber) == false do
    format [subscriber], []  # Use when `Repo.get_by! Subscriber, phone_number: phone_number`
  end

  defp put_phone_number_list [h|t], target, acc do
    acc = acc ++ [h.phone_number]
    put_phone_number_list t, target, acc
  end

  defp put_phone_number_list [], target, acc do
    elem = Map.put List.first(target), "index", acc
    target = List.replace_at target, 0, elem
  end

  defp add_index target, subscribers do
    put_phone_number_list subscribers, target, []
  end

  defp format [h|t], acc do
    subscriber = %{
      phone_number: h.phone_number,
      sim_id: h.sim_id,
      status: h.status,
      created_at: h.inserted_at,
      updated_at: h.updated_at,
    }
    res = format t, acc ++ [subscriber]

    add_index res, [h] ++ t
  end

  defp format [], acc do
    acc
  end

end
